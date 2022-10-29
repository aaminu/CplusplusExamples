#include <iostream>
#include <vector>
#include <tuple>
#include <string>

void sieveTester(void);

int main()
{

    sieveTester();
    return 0;
}

// Function to perform sieving of Eratosthenes
std::vector<std::tuple<int, bool>> sieveOfEratosthenes(const long &prime_limit)
{
    std::vector<std::tuple<int, bool>> primes;

    primes.push_back(std::make_tuple(2, true)); // push back the first prime number
    for (size_t i = 3; i <= prime_limit; ++i)   // push all other odd numbers to vector and set to true
    {
        if (i % 2 != 0)
            primes.push_back(std::make_tuple(i, true));
    }

    if (primes.size() <= 4) // Check if vector contains just the first 4 prime number or less
        return primes;

    for (size_t j{0}; j < (primes.size() - 1); ++j)
    {
        for (size_t k{j + 1}; k <= (primes.size() - 1); ++k)
        {
            // check to see if it has been categorized as not prime by the l-evaluation
            if (std::get<1>(primes[k]) && (std::get<0>(primes[k]) % std::get<0>(primes[j]) == 0))
                primes[k] = std::make_tuple(std::get<0>(primes[k]), false);
        }
    }

    return primes;
}

// Print function for container
void print_container(std::vector<std::tuple<int, bool>> &c, const long &limit_)
{
    std::cout << "The Prime numbers contained within the limit {" << limit_ << ((c.size() > 1) ? "} are: " : "} is: ");
    for (auto &elem : c)
    {
        if (std::get<1>(elem))
            std::cout << std::get<0>(elem) << " ";
    }
    std::cout << std::endl
              << std::endl;
}

// Test function with input functionality
void sieveTester(void)
{
    long limitValue{};
    std::vector<std::tuple<int, bool>> container;

    while (true)
    {
        std::string tmpStr{};
        std::cout << "Enter limit value for the Prime numbers: ";
        getline(std::cin, tmpStr);
        try
        {
            limitValue = std::stol(tmpStr);
        }
        catch (const std::exception &e)
        {
            std::cerr << "Invalid Arguements!" << '\n';
            std::cout << "Input must be an integer!" << std::endl;
            continue;
        }

        if (limitValue < 2)
        {
            std::cout << std::endl;
            std::cout << "There are no prime numbers within the selected range!" << std::endl;
            std::cout << "Number has to greater than or equal to 2!" << std::endl;
            std::cout << std::endl;
            continue;
        }

        break;
    }

    container = sieveOfEratosthenes(limitValue);
    print_container(container, limitValue);
}
