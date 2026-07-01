# Custom Key-Value Database Store

## Description
This program is a simple command-line key-value store done on C++. It uses core C++ skills such as streams, inheritance, and smart pointers and software construction principles such as SOLID and unit testing.

## Usage
The idea is that the user can type in a multitude of different commands in the command line involving key-value pairs. The user input commands are read then parsed, which turns the raw text into instruction and data for the command object. The key-value store class handles the data based on the instruction given such as set, get, and remove. The storage engine decides where the data lives and its functions include save and load. Different command classes that inherit from the base command class call the other parts of the program. Using a smart pointer to command, we let the program decide which command to execute.

