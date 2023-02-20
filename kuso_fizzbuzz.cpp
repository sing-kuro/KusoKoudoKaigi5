#include <iostream>
#include <string>

namespace kuso
{

	constexpr bool test_3(int x)
	{
		return !((x & 1) + ~((x & 2) >> 1) + ((x & 4) >> 2) + ~(x >> 3) + 2);
	}


	constexpr bool test_5(int x)
	{
		return !((x & 3) + ~(x >> 2) + 1);
	}

	const std::string fizz[2]{ "","Fizz" }, buzz[2]{ "","Buzz" };

	std::string fizzbuzz(int x)
	{
		std::string result = fizz[test_3(x)] + buzz[test_5(x)];
		return result.empty() ? std::to_string(x) : result;
	}

}

int main()
{
	for (int i = 1; i < 1<<4; i++)
	{
		std::cout << kuso::fizzbuzz(i) << std::endl;
	}
}

//倍数判定にビット演算を使用、条件分岐を一度だけにすることで高速化を図った(おそらく逆に遅い)。15までという事だったので入力が16以上の時の動作は予想外のものになる。
