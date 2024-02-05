#include <iostream>

//Check for duplicates
bool
RemoveDupe (int nums[], int n)
{
  if (n == 0)
	{
	  return false;
	}

  int index = 0;

  for (int i = 1; i < n; ++i)
	{
	  if (nums[i] != nums[index])
		{
		  index++;
		  nums[index] = nums[i];
		}
	}

  return (index + 1 < n);
}

int
main ()
{
  int n;
  std::cout << "Enter number of integers: ";
  std::cin >> n;

  int nums[n];
  for (int i = 0; i < n; i++)
	{
	  std::cout << "Enter integer " << i + 1 << ": ";
	  std::cin >> nums[i];
	}

  bool DupeDetected = RemoveDupe (nums, n);

  std::cout << std::boolalpha;
  std::cout << DupeDetected << "\n";

  return 0;
}
