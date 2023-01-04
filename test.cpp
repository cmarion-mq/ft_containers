#include <vector>
#include <iostream>

int main ()
{
  std::vector<int> myvector (10);   // 10 zero-initialized ints

  // assign some values:
  for (unsigned i=0; i<myvector.size(); i++)
    myvector.at(i)=i;

  std::cout << "myvector contains:";
  for (unsigned i=0; i<myvector.size() + 3; i++)
    std::cout << ' ' << myvector.at(i);
  std::cout << '\n';

  return 0;
}
