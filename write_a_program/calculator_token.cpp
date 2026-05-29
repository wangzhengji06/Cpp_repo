#include <iostream>
#include <stdexcept>

class Token {
public:
  char kind;
  double value;

  Token(char k) : kind{k}, value{0.0} {}
  Token(char k, double v) : kind{k}, value{v} {}
};

class Token_stream {
public:
  Token get();
  void putback(Token t);

private:
  bool full = false;
  Token buffer{'0'}; // dummy initial token
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
  case '(':
  case ')':
  case ';':
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
    return Token{'8', val}; // '8' means "number"
  }

  default:
    throw std::runtime_error("Bad token");
  }
}

Token_stream ts;

// Function declarations
double expression();
double term();
double primary();

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

  case '8':
    return t.value;

  default:
    throw std::runtime_error("primary expected!");
  }
}

int main() {
  try {
    std::cout << "Enter expressions. Use ; to print result.\n";

    while (std::cin) {
      Token t = ts.get();

      if (t.kind == ';')
        continue;

      ts.putback(t);
      std::cout << "= " << expression() << '\n';
    }
  } catch (std::exception &e) {
    std::cerr << e.what() << '\n';
    return 1;
  } catch (...) {
    std::cerr << "exception\n";
    return 2;
  }
}
