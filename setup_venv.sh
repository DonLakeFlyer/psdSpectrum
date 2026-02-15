#!/bin/bash

# Create virtual environment
python3 -m venv venv

# Activate virtual environment
source venv/bin/activate

# Upgrade pip
pip install --upgrade pip

# Install required dependencies
pip install numpy matplotlib scipy

echo "Virtual environment setup complete!"
echo ""
echo "IMPORTANT: To activate the environment in your current shell, run:"
echo "  source venv/bin/activate"
echo ""
echo "Note: The script attempted to activate it, but you must source this script"
echo "(not bash it) for the activation to persist in your shell. Run:"
echo "  source setup_venv.sh"
echo "instead of:"
echo "  bash setup_venv.sh"
