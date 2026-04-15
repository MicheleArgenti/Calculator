#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <cmath>

using namespace std;

class Calculator
{
private:
  // Variables
  double currentValue;
  string memory;
  vector<string> history; // STL vector to store calculation history
  const string HISTORY_FILE = "calculator_history.txt";

  // Helper function to format numbers
  string formatNumber(double num)
  {
    stringstream ss;
    ss << fixed << setprecision(2) << num;
    return ss.str();
  }

  // Write history to file
  void saveToFile()
  {
    ofstream outFile(HISTORY_FILE, ios::app); // Append mode
    if (outFile.is_open())
    {
      outFile << memory << "\n";
      outFile.close();
    }
  }

  // Read history from file
  void loadHistoryFromFile()
  {
    ifstream inFile(HISTORY_FILE);
    if (inFile.is_open())
    {
      string line;
      while (getline(inFile, line))
      {
        if (!line.empty())
        {
          history.push_back(line);
        }
      }
      inFile.close();
    }
  }

  // Expression evaluator for simple arithmetic
  double evaluateExpression(double a, double b, char op)
  {
    switch (op)
    { // Conditional example
    case '+':
      return a + b;
    case '-':
      return a - b;
    case '*':
      return a * b;
    case '/':
      if (b != 0)
        return a / b;
      else
        throw runtime_error("Division by zero!");
    default:
      return 0;
    }
  }

public:
  // Constructor
  Calculator() : currentValue(0.0), memory("")
  {
    loadHistoryFromFile();
    addToHistory("=== Calculator Started ===");
  }

  // Destructor
  ~Calculator()
  {
    addToHistory("=== Calculator Closed ===");
    saveToFile();
  }

  // Function to add calculation to history
  void addToHistory(string entry)
  {
    history.push_back(entry);
    // Keep history manageable (last 100 entries)
    if (history.size() > 100)
    {
      history.erase(history.begin());
    }
  }

  // Basic arithmetic operations (Functions example)
  double add(double a, double b)
  {
    double result = a + b; // Expression
    string entry = formatNumber(a) + " + " + formatNumber(b) + " = " + formatNumber(result);
    memory = entry;
    addToHistory(entry);
    saveToFile();
    return result;
  }

  double subtract(double a, double b)
  {
    double result = a - b;
    string entry = formatNumber(a) + " - " + formatNumber(b) + " = " + formatNumber(result);
    memory = entry;
    addToHistory(entry);
    saveToFile();
    return result;
  }

  double multiply(double a, double b)
  {
    double result = a * b;
    string entry = formatNumber(a) + " × " + formatNumber(b) + " = " + formatNumber(result);
    memory = entry;
    addToHistory(entry);
    saveToFile();
    return result;
  }

  double divide(double a, double b)
  {
    if (b == 0)
    {
      throw runtime_error("Cannot divide by zero!");
    }
    double result = a / b;
    string entry = formatNumber(a) + " ÷ " + formatNumber(b) + " = " + formatNumber(result);
    memory = entry;
    addToHistory(entry);
    saveToFile();
    return result;
  }

  // Advanced operations
  double power(double base, double exponent)
  {
    double result = pow(base, exponent);
    string entry = formatNumber(base) + "^" + formatNumber(exponent) + " = " + formatNumber(result);
    memory = entry;
    addToHistory(entry);
    saveToFile();
    return result;
  }

  double squareRoot(double num)
  {
    if (num < 0)
    {
      throw runtime_error("Cannot take square root of negative number!");
    }
    double result = sqrt(num);
    string entry = "√" + formatNumber(num) + " = " + formatNumber(result);
    memory = entry;
    addToHistory(entry);
    saveToFile();
    return result;
  }

  double percentage(double num, double percent)
  {
    double result = num * (percent / 100.0);
    string entry = formatNumber(percent) + "% of " + formatNumber(num) + " = " + formatNumber(result);
    memory = entry;
    addToHistory(entry);
    saveToFile();
    return result;
  }

  // Memory functions
  string getLastCalculation()
  {
    return memory;
  }

  // Display history (using loop)
  void showHistory()
  {
    if (history.empty())
    {
      cout << "No calculation history available." << endl;
      return;
    }

    cout << "\n╔════════════════════════════════════════╗" << endl;
    cout << "║         CALCULATION HISTORY            ║" << endl;
    cout << "╠════════════════════════════════════════╣" << endl;

    // Loop example
    for (size_t i = 0; i < history.size(); i++)
    {
      cout << "║ " << setw(38) << left << history[i] << "║" << endl;
    }

    cout << "╚════════════════════════════════════════╝" << endl;
  }

  // Clear history
  void clearHistory()
  {
    history.clear();
    addToHistory("=== History Cleared ===");
    cout << "History cleared successfully!" << endl;

    // Also clear the file
    ofstream outFile(HISTORY_FILE, ios::trunc);
    outFile.close();
  }

  // Export history to file
  void exportHistoryToFile(string filename)
  {
    ofstream outFile(filename);
    if (outFile.is_open())
    {
      for (const string &entry : history)
      { // Range-based loop
        outFile << entry << endl;
      }
      outFile.close();
      cout << "History exported to " << filename << " successfully!" << endl;
    }
    else
    {
      cout << "Error: Could not create export file." << endl;
    }
  }

  // Run interactive calculator menu
  void run()
  {
    int choice;
    double num1, num2;

    while (true)
    { // Loop example
      cout << "" << endl;
      cout << "         CALCULATOR APPLICATION         " << endl;
      cout << "" << endl;
      cout << "  1. Addition (+)                      " << endl;
      cout << "  2. Subtraction (-)                   " << endl;
      cout << "  3. Multiplication (×)                " << endl;
      cout << "  4. Division (÷)                      " << endl;
      cout << "  5. Power (x^y)                       " << endl;
      cout << "  6. Square Root (√x)                  " << endl;
      cout << "  7. Percentage                        " << endl;
      cout << "  8. Show History                      " << endl;
      cout << "  9. Clear History                     " << endl;
      cout << " 10. Export History to File            " << endl;
      cout << "  11. View Last Calculation             " << endl;
      cout << "  0. Exit                              " << endl;
      cout << "" << endl;
      cout << "Enter your choice: ";
      cin >> choice;

      // Conditional example
      if (choice == 0)
      {
        cout << "Thank you for using the calculator! Goodbye!" << endl;
        break;
      }

      try
      {
        switch (choice)
        { // Conditional example
        case 1:
          cout << "Enter first number: ";
          cin >> num1;
          cout << "Enter second number: ";
          cin >> num2;
          cout << "Result: " << formatNumber(add(num1, num2)) << endl;
          break;

        case 2:
          cout << "Enter first number: ";
          cin >> num1;
          cout << "Enter second number: ";
          cin >> num2;
          cout << "Result: " << formatNumber(subtract(num1, num2)) << endl;
          break;

        case 3:
          cout << "Enter first number: ";
          cin >> num1;
          cout << "Enter second number: ";
          cin >> num2;
          cout << "Result: " << formatNumber(multiply(num1, num2)) << endl;
          break;

        case 4:
          cout << "Enter numerator: ";
          cin >> num1;
          cout << "Enter denominator: ";
          cin >> num2;
          cout << "Result: " << formatNumber(divide(num1, num2)) << endl;
          break;

        case 5:
          cout << "Enter base: ";
          cin >> num1;
          cout << "Enter exponent: ";
          cin >> num2;
          cout << "Result: " << formatNumber(power(num1, num2)) << endl;
          break;

        case 6:
          cout << "Enter number: ";
          cin >> num1;
          cout << "Result: " << formatNumber(squareRoot(num1)) << endl;
          break;

        case 7:
          cout << "Enter number: ";
          cin >> num1;
          cout << "Enter percentage: ";
          cin >> num2;
          cout << "Result: " << formatNumber(percentage(num1, num2)) << endl;
          break;

        case 8:
          showHistory();
          break;

        case 9:
          clearHistory();
          break;

        case 10:
        {
          string filename;
          cout << "Enter filename (e.g., history.txt): ";
          cin >> filename;
          exportHistoryToFile(filename);
        }
        break;

        case 11:
          if (memory.empty())
          {
            cout << "No calculations performed yet." << endl;
          }
          else
          {
            cout << "Last calculation: " << memory << endl;
          }
          break;

        default:
          cout << "Invalid choice! Please try again." << endl;
        }
      }
      catch (const exception &e)
      {
        cout << "Error: " << e.what() << endl;
      }
    }
  }
};

// Main function
int main()
{
  cout << "Welcome to the Advanced Calculator Application!" << endl;
  cout << "==============================================" << endl;

  // Create calculator object (demonstrates class usage)
  Calculator myCalculator;

  // Run the calculator
  myCalculator.run();

  return 0;
}