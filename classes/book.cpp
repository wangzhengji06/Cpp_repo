#include <cctype>
#include <ostream>
#include <string>
class Book {
public:
  class Invalid {};
  Book(std::string isbn_no, std::string title_str, std::string author_str,
       int copyright_time);
  std::string get_isbn() const;
  std::string get_title() const;
  std::string get_author() const;
  int get_copyright_year() const;
  bool is_checkedout() const;
  void checkin();
  void checkout();

private:
  std::string isbn;
  std::string title;
  std::string author;
  int copyright_year;
  bool checked_out = false;
  static bool is_valid_isbn(const std::string &isbn);
};

bool all_digits(const std::string &s, int begin, int end) {
  if (begin >= end)
    return false;
  if (end > s.size())
    end = s.size();
  for (int i = begin; i < end; ++i)
    if (!std::isdigit(s[i]))
      return false;
  return true;
}

bool Book::is_valid_isbn(const std::string &isbn) {
  auto p1 = isbn.find('-');
  if (p1 == std::string::npos)
    return false;

  auto p2 = isbn.find('-', p1 + 1);
  if (p2 == std::string::npos)
    return false;

  auto p3 = isbn.find('-', p2 + 1);
  if (p3 == std::string::npos)
    return false;

  if (isbn.find('-', p3 + 1) != std::string::npos)
    return false;

  if (!all_digits(isbn, 0, p1))
    return false;
  if (!all_digits(isbn, p1 + 1, p2))
    return false;
  if (!all_digits(isbn, p2 + 1, p3))
    return false;

  if (p3 + 2 != isbn.size())
    return false;

  char last = isbn[p3 + 1];

  return std::isdigit(static_cast<unsigned char>(last)) ||
         std::isalpha(static_cast<unsigned char>(last));
}

Book::Book(std::string isbn_no, std::string title_str, std::string author_str,
           int copyright_time)
    : isbn{isbn_no}, title{title_str}, author{author_str},
      copyright_year{copyright_time} {
  if (!is_valid_isbn(isbn_no))
    throw Invalid{};
}

std::string Book::get_isbn() const { return isbn; }

std::string Book::get_title() const { return title; }

std::string Book::get_author() const { return author; }

int Book::get_copyright_year() const { return copyright_year; }

bool Book::is_checkedout() const { return checked_out; }

void Book::checkin() { checked_out = false; }

void Book::checkout() { checked_out = true; }

bool operator==(const Book &b1, const Book &b2) {
  return b1.get_isbn() == b2.get_isbn();
}

bool operator!=(const Book &b1, const Book &b2) { return !(b1 == b2); }

std::ostream &operator<<(std::ostream &os, const Book &b) {
  return os << b.get_title() << "\n"
            << b.get_author() << "\n"
            << b.get_isbn() << "\n";
}
