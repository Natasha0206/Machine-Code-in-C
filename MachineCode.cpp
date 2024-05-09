#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Structure to represent an instruction
struct Instruction {
    string opcode;
    string operand1;
    string operand2;
    string result;

    Instruction(string op, string op1, string op2, string res) : opcode(op), operand1(op1), operand2(op2), result(res) {}
};

// Function to generate MOV instruction
Instruction generateMOV(string source, string destination) {
    return Instruction("MOV", source, "", destination);
}

// Function to generate ADD instruction
Instruction generateADD(string operand1, string operand2, string result) {
    return Instruction("ADD", operand1, operand2, result);
}

// Function to generate LD instruction
Instruction generateLD(string address, string registerName) {
    return Instruction("LD", address, "", registerName);
}

// Function to display instructions
void displayInstructions(const vector<Instruction>& instructions) {
    cout << "Instructions:\n";
    cout << "-----------------------------\n";
    for (const auto& instr : instructions) {
        cout << instr.opcode << " " << instr.operand1;
        if (!instr.operand2.empty()) {
            cout << ", " << instr.operand2;
        }
        if (!instr.result.empty()) {
            cout << " => " << instr.result;
        }
        cout << endl;
    }
    cout << "-----------------------------\n";
}

int main() {
    // Example code generation
    vector<Instruction> instructions;
    instructions.push_back(generateMOV("A", "B"));   // Move the value in register A to register B
    instructions.push_back(generateADD("A", "B", "C"));   // Add the values in registers A and B, store the result in register C
    instructions.push_back(generateLD("100", "A"));   // Load the value at memory address 100 into register A

    // Display the generated instructions
    displayInstructions(instructions);

    return 0;
}