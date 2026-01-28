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
echo "To activate the environment, run: source venv/bin/activate"
