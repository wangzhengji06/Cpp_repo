
#include <istream>
#include <stdexcept>
#include <vector>
void fill_vector(std::istream &ist, std::vector<int> &v, char terminator)
// read integers from ist into v until we reach eof() or terminator
{
  ist.exceptions(ist.exceptions() | std::ios::badbit | std::ios::failbit);
  for (int x; ist >> x;)
    v.push_back(x);
  if (ist.eof()) // fine: we found the end of file
    return;
  // The two if statement afterward is not necessary now because if it is in
  // fail() or bad() state, it will automatically throw exceptions
  if (ist.bad()) // stream corrupted;
    throw std::runtime_error("Something serious happened");
  if (ist.fail()) { // clean up the mess as best we can and report the
                    // probleist.clear(); // clear stream state, so that we can
                    // look for terminator
    char c = 0;
    ist >> c;                       // read a character, hopefully terminator
    if (c != terminator) {          // unexpected character
      ist.unget();                  // put that character back
      ist.clear(std::ios::failbit); // set the state to fail()
    }
  }
}
