# The Coalition Race
📌 Overview
This project implements a simulation of a coalition race in a fictional democracy called SPLand.
Agents from different political parties negotiate and attempt to form coalitions, with the goal of reaching 61 mandates as quickly as possible.
The project was developed as part of the Extended Systems Programming Lab (SPL231) at BGU.

# 🎯 Goals
Gain experience with C++ OOP design and implementation.
Work with graphs, agents, and policies to simulate political processes.
Apply memory management best practices, including the Rule of 5.
Learn to parse and generate JSON configuration/output files.

# ⚙️ Features
Parties represented as vertices in a graph.
Collaborations represented as edges with similarity scores (weights).
Agents simulate party actions and extend coalitions.
Multiple selection policies (e.g., based on mandates or edge weights).
Multiple join policies (e.g., largest mandate coalition or last offer).
Simulation runs step-by-step until a coalition forms or all parties join.
Output generated in JSON format for analysis and visualization.

# 🏗️ Project Structure
├── include/         # Header files (Agent.h, Graph.h, Party.h, etc.)
├── src/             # Source files (Agent.cpp, Graph.cpp, Simulation.cpp, etc.)
├── bin/             # Build output (empty before compilation)
├── Makefile         # Build instructions
└── visualization.py # Python script for visualizing coalition graphs

# 🛠️ Build & Run
# Prerequisites
Linux environment
g++ with multilib support
Python 3 with networkx and matplotlib (for visualization)
Valgrind (for memory check)

# Install on Ubuntu/Debian:
sudo apt update
sudo apt install g++ make valgrind python3-pip
pip3 install networkx matplotlib

# Build
make

# Run
./bin/cRace <config_file.json>
Example:
./bin/cRace examples/01.json

# The simulation produces an output JSON file (e.g., 01.out) that can be visualized with:
python3 visualization.py 01.out

# 🧪 Testing
# Compare your output with the expected results using:
diff -s expected/01.out output/01.out

# Run with Valgrind to ensure no memory leaks:
valgrind --leak-check=full --show-reachable=yes ./bin/cRace examples/01.json
------------------------------------------------------------------------------------------

#📖 Notes
Works only with valid JSON configuration files.
Supports multiple strategies for agents and coalitions.
Educational purpose only – designed for learning simulation & system programming concepts.


