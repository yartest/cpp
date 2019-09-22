#include <iostream>
#include <vector>
#include <set>
#include <deque>
#include <sstream>
#include <thread>
#include <random>
#include <memory>
#include <algorithm>
#include <iterator>

using namespace std;

std::random_device g_randomDevice;
std::mt19937 g_randomGen(g_randomDevice());
/*
 * Element{i, j}
 *
              | 0 | 1 | 2 | . | j | . |N-1|
            -------------------------------
            0 |   |   |   |   |   |   |   |
            -------------------------------
            1 |   |   |   |   |   |   |   |
            -------------------------------
            . |   |   |   |   |   |   |   |
            -------------------------------
            i |   |   |   |   | E |   |   |
            -------------------------------
            . |   |   |   |   |   |   |   |
            -------------------------------
           N-1|   |   |   |   |   |   |   |
            -------------------------------
*/
namespace sudoku {
    const unsigned FIELD_SIZE = 9;
    const unsigned BLOCK_SIZE = 3;
    const set<unsigned> ALL_POSSIBLE_VALUES = {1, 2, 3, 4, 5, 6, 7, 8, 9};

// Position contains coordinates inside
    struct Position {
        unsigned i = 0;
        unsigned j = 0;

        Position(unsigned first, unsigned second):i{first}, j{second}{}

        Position() = default;
        Position(const Position&) = default;
        Position& operator = (const Position&) = default;
        Position(Position&&) = default;
        Position& operator = (Position&&) = default;
        ~Position() = default;
    };

    inline bool operator == (const Position &first, const Position &second) {
        return first.i == second.i && first.j == second.j;
    }

    inline bool operator < (const Position &first, const Position &second) {
        return first.i < second.i || (first.i == second.i && first.j < second.j);
    }

// Element contains own position and own value
// also has sequence of all related elements
    struct Element {
    public:
        Position pos;
        unsigned value = 0;
        set<Position> neighbors{}; // all related elements to the current one

        Element() {}

        void setPosition(const Position &inPos) {
            pos = inPos;
            setNeighbors();
        }

    private:
        void setNeighbors () {

            for (unsigned i = 0; i < FIELD_SIZE; ++i) {
                // set row neighbors
                neighbors.insert({i, pos.j});
                // set column neighbors
                neighbors.insert({pos.i, i});
            }

            unsigned yStartId = (pos.i / BLOCK_SIZE) * BLOCK_SIZE;
            unsigned xStartId = (pos.j / BLOCK_SIZE) * BLOCK_SIZE;
            unsigned yEndId = yStartId + BLOCK_SIZE - 1;
            unsigned xEndId = xStartId + BLOCK_SIZE - 1;

            // set block neighbors
            for (unsigned i = yStartId; i <= yEndId; ++i) {
                for (unsigned j = xStartId; j <= xEndId; ++j) {
                    neighbors.insert({i, j});
                }
            }
        }
    };//struct Element {

//using cellQueue = deque<shared_ptr<SudokuCell>>;

//Field contains all sudoku elements
    class Field {
        deque<shared_ptr<Element>> elements;

    public:

        Field() {
            for (unsigned i = 0; i < FIELD_SIZE; i++) {
                for(unsigned j = 0; j < FIELD_SIZE; j++) {
                    auto element = make_shared<Element>(Element());
                    element->setPosition({i, j});
                    elements.push_back(element);
                }
            }
        }
        //SudokuBoard(const SudokuBoard&) = delete;
        //SudokuBoard(SudokuBoard&&) = delete;
        //SudokuBoard& operator = (const SudokuBoard&) = delete;
        //SudokuBoard& operator = SudokuBoard(SudokuBoard&&) = delete;
        //~SudokuBoard() = delete;

        void generateField() {
            generateFieldBackTracking(0);
        }

        // Take index and return Position coordinate
        Position resolveIndex(unsigned index) {
            return Position{index / FIELD_SIZE, index % FIELD_SIZE};
        }

        // Take Position coordinate and return index
        unsigned resolvePosition(const Position &position) {
            return position.i * FIELD_SIZE + position.j;
        }

        shared_ptr<Element> at(unsigned index) {
            return this->elements.at(index);
        }

        shared_ptr<Element> at(const Position &position) {
            auto index = this->resolvePosition(position);
            return this->at(index);
        }

        // Print the sudoku field
        void printBoard() {
            cout << '\n' << "----------------------------------" << '\n';

            for(unsigned i = 0; i < FIELD_SIZE; i++) {
                cout << "| ";

                for(unsigned j = 0; j < FIELD_SIZE; j++) {
                    auto index = resolvePosition({i, j});
                    auto element = elements.at(index);
                    auto value = element->value;

                    if (value > 0)  {
                        cout << value << "  ";
                    } else {
                        cout << "   ";
                    }

                    if (j % BLOCK_SIZE == BLOCK_SIZE - 1) {
                        cout << "| ";
                    }
                }
                if (i % BLOCK_SIZE == BLOCK_SIZE - 1) {
                    cout << '\n' << "----------------------------------";
                }
                cout << '\n';
            }
        }

        // Serialize
        string serialize() {
            stringstream ostream;
            for(auto element: elements) {
                ostream << element->value;
            }
            return ostream.str();
        }
    private:
        bool generateFieldBackTracking(unsigned elementId) {

            auto &element = elements.at(elementId);

            set<int> neighborValues = {};

            for (auto &neighbor : element->neighbors) {
                auto value = this->at(neighbor)->value;
                neighborValues.insert(value);
            }

            vector<int> newValues;
            set_difference(
                ALL_POSSIBLE_VALUES.begin(), ALL_POSSIBLE_VALUES.end(),
                neighborValues.begin(), neighborValues.end(),
                inserter(newValues, newValues.begin())
            );
            shuffle(newValues.begin(), newValues.end(), g_randomGen);

            for (auto &newValue: newValues) {
                element->value = newValue;
                if (elementId == elements.size() - 1) {
                    return true;
                }
                if (generateFieldBackTracking(elementId + 1) == true) {
                    return true;
                }
            }
            // static unsigned goBackCounter = 0;
            // cout << "goBackCounter: " << ++goBackCounter << endl;
            element->value = 0;
            return false;
        }

    };
};// namespace sudoku {

void printUsageError(char *programName) {
    cerr << "Usage: " << programName << " board_count [--all-neighbors]" << '\n';
}

void test_functions() {

    srand(time(NULL));

    sudoku::Field field{};
    field.generateField();
    field.printBoard();
    //stringstream output;
    //output << field.serialize() << '\n';
}
