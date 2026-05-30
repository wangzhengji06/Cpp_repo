#include <cctype>
#include <exception>
#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>

/*
This program implements a basic expression calculator.
Input from cin; output to cout.

Grammar:

Calculation:
    Statement
    Print
    Quit
    Calculation Statement

Statement:
    Declaration
    Expression

Declaration:
    "let" Name "=" Expression

Expression:
    Term
    Expression "+" Term
    Expression "-" Term

Term:
    Primary
    Term "*" Primary
    Term "/" Primary
    Term "%" Primary

Primary:
    Number
    Name
    "(" Expression ")"
    "-" Primary
    "+" Primary

Number:
    floating-point-literal

Name:
    letter
    letter followed by letters and digits

Print:
    ";"

Quit:
    "q"
*/

constexpr char number = '8';
constexpr char quit = 'q';
constexpr char print = ';';
constexpr char name = 'a';
constexpr char let = 'L';

const std::string declkey = "let";
const std::string prompt = "> ";
const std::string result = "= ";

class Variable {
public:
  std::string name;
  double value;
};

std::vector<Variable> var_table;

double get_value(std::string s) {
  for (const Variable &v : var_table) {
    if (v.name == s)
      return v.value;
  }

  throw std::runtime_error("trying to read undefined variable: " + s);
}

void set_value(std::string s, double d) {
  for (Variable &v : var_table) {
    if (v.name == s) {
      v.value = d;
      return;
    }
  }

  throw std::runtime_error("trying to write undefined variable: " + s);
}

bool is_declared(std::string var) {
  for (const Variable &v : var_table) {
    if (v.name == var)
      return true;
  }

  return false;
}

double define_name(std::string var, double val) {
  if (is_declared(var))
    throw std::runtime_error(var + " declared twice");

  var_table.push_back(Variable{var, val});
  return val;
}

class Token {
public:
  char kind;
  double value;
  std::string name;

  Token(char k) : kind{k}, value{0.0}, name{""} {}
  Token(char k, double v) : kind{k}, value{v}, name{""} {}
  Token(char k, std::string n) : kind{k}, value{0.0}, name{n} {}
};

class Token_stream {
public:
  Token get();
  void putback(Token t);
  void ignore(char c);

private:
  bool full = false;
  Token buffer{'0'};
};

void Token_stream::putback(Token t) {
  if (full)
    throw std::runtime_error("putback() into a full buffer");

  buffer = t;
  full = true;
}

Token Token_stream::get() {
  if (full) {
    full = false;
    return buffer;
  }

  char ch = 0;
  if (!(std::cin >> ch))
    throw std::runtime_error("no input");

  switch (ch) {
  case '+':
  case '-':
  case '*':
  case '/':
  case '%':
  case '(':
  case ')':
  case '=':
  case print:
  case quit:
    return Token{ch};

  case '.':
  case '0':
  case '1':
  case '2':
  case '3':
  case '4':
  case '5':
  case '6':
  case '7':
  case '8':
  case '9': {
    std::cin.putback(ch);
    double val = 0;
    std::cin >> val;
    return Token{number, val};
  }

  default:
    if (std::isalpha(static_cast<unsigned char>(ch))) {
      std::string s;
      s += ch;

      while (std::cin.get(ch)) {
        if (std::isalpha(static_cast<unsigned char>(ch)) ||
            std::isdigit(static_cast<unsigned char>(ch)) || ch == '_') {
          s += ch;
        } else {
          std::cin.putback(ch);
          break;
        }
      }

      if (s == declkey)
        return Token{let};

      return Token{name, s};
    }

    throw std::runtime_error("Bad token");
  }
}

void Token_stream::ignore(char c) {
  if (full && buffer.kind == c) {
    full = false;
    return;
  }

  full = false;

  char ch = 0;
  while (std::cin >> ch) {
    if (ch == c)
      return;
  }
}

Token_stream ts;

double statement();
double declaration();
double expression();
double term();
double primary();

double statement() {
  Token t = ts.get();

  switch (t.kind) {
  case let:
    return declaration();

  default:
    ts.putback(t);
    return expression();
  }
}

double declaration() {
  Token t = ts.get();

  if (t.kind != name)
    throw std::runtime_error("name expected in declaration");

  std::string var_name = t.name;

  Token t2 = ts.get();

  if (t2.kind != '=')
    throw std::runtime_error("= missing in declaration of " + var_name);

  double d = expression();

  define_name(var_name, d);

  return d;
}

double expression() {
  double left = term();
  Token t = ts.get();

  while (true) {
    switch (t.kind) {
    case '+':
      left += term();
      t = ts.get();
      break;

    case '-':
      left -= term();
      t = ts.get();
      break;

    default:
      ts.putback(t);
      return left;
    }
  }
}

double term() {
  double left = primary();
  Token t = ts.get();

  while (true) {
    switch (t.kind) {
    case '*':
      left *= primary();
      t = ts.get();
      break;

    case '/': {
      double d = primary();

      if (d == 0)
        throw std::runtime_error("divide by zero");

      left /= d;
      t = ts.get();
      break;
    }

    case '%': {
      int i1 = static_cast<int>(left);
      int i2 = static_cast<int>(primary());

      if (i2 == 0)
        throw std::runtime_error("%: divide by zero");

      left = i1 % i2;
      t = ts.get();
      break;
    }

    default:
      ts.putback(t);
      return left;
    }
  }
}

double primary() {
  Token t = ts.get();

  switch (t.kind) {
  case '(': {
    double d = expression();
    t = ts.get();

    if (t.kind != ')')
      throw std::runtime_error("')' expected");

    return d;
  }

  case number:
    return t.value;

  case name:
    return get_value(t.name);

  case '-':
    return -primary();

  case '+':
    return primary();

  default:
    throw std::runtime_error("primary expected");
  }
}

void clean_up_mess() { ts.ignore(print); }

void calculate() {
  while (std::cin) {
    try {
      std::cout << prompt;

      Token t = ts.get();

      while (t.kind == print)
        t = ts.get();

      if (t.kind == quit)
        return;

      ts.putback(t);

      std::cout << result << statement() << '\n';
    } catch (std::exception &e) {
      std::cerr << e.what() << '\n';
      clean_up_mess();
    }
  }
}

int main() try {
  define_name("pi", 3.1415926535);
  define_name("e", 2.7182818284);

  calculate();

  return 0;
} catch (std::exception &e) {
  std::cerr << e.what() << '\n';
  return 1;
} catch (...) {
  std::cerr << "exception\n";
  return 2;
}
