#include <iostream>
#include <chrono>
#include <array>

using namespace std;

// here you should implement your own magic checker.
// returns true if the square is magic, false otherwise
//
//                8 1 6    this is
// "816357492" =  3 5 7    a magic
//                4 9 2    square
//
const std::array<uint64_t, 8> magic_numbers
{
3545515123101087289, 3690191062107239479,
3544956562637535289, 3978984379655991859,
3689073941180135479, 4123101758198592049,
3977867258728887859, 4122543197735040049
};
bool check_if_magic(const std::string& square)
{
  if(square[4] != '5')
    return false;

  uint64_t nr = *(reinterpret_cast<const uint32_t*>(square.data()));
  nr <<= 32;
  nr +=	*(reinterpret_cast<const uint32_t*>(square.data()+5));

  if (nr <= 3690191062107239479)
    if (nr <= 3545515123101087289)
      if (nr < 3545515123101087289)
        return nr == 3544956562637535289;
      else
        return nr == 3545515123101087289;
    else
      if (nr < 3690191062107239479)
        return nr == 3689073941180135479;
      else
        return nr == 3690191062107239479;
  else
    if (nr <= 3978984379655991859)
      if (nr < 3978984379655991859)
        return nr == 3977867258728887859;
      else
        return nr == 3978984379655991859;
    else
      if (nr < 4123101758198592049)
        return nr == 4122543197735040049;
      else
        return nr == 4123101758198592049;
}

// this generates all possible combinations of 1-9 cyphers
// that may or may not form a magic square
static string buffer = "000000000";
void generate_or_check(int index_or_check = 8){
  if(index_or_check == -1){
    if(check_if_magic(buffer))
      cout << buffer << " ";
    return;
  }

  for(auto i = 1u; i < 10; ++i){
    buffer[index_or_check] = '0' + i;
    generate_or_check(index_or_check-1);
  }
}

// this runs the generator and measures time
int main()
  {
  auto start = std::chrono::system_clock::now();
  generate_or_check();
  auto end = std::chrono::system_clock::now();
  std::chrono::duration<double> difference = end - start;
  std::cout << difference.count() << "\n\n";
  }

