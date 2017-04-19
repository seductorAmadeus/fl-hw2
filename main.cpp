#include <iostream>

// Set of states deterministic finite state machine
enum StateDeterministicFiniteStateMachine
{
	A, B, C, D, E, F, G, ER
};

// Returns the accessory of the chain of symbols
// if current_state != ER, then return true,
// else return false;
bool CheckStringCondition()
{
	StateDeterministicFiniteStateMachine current_state;
	std::string str; // string of input characters
	int i = 0;
	current_state = A;
	std::getline(std::cin, str);
	do
	{
		switch (current_state)
		{
			case A:
				switch (str[i])
				{
					case 'a':
						current_state = B;
						break;
					default:
						current_state = ER;
						break;
				}
				break;
			case B:
				switch (str[i])
				{
					case 'a':
						current_state = C;
						break;
					case 'b':
						current_state = D;
						break;
					default:
						current_state = ER;
						break;
				}
				break;
			case C:
				switch (str[i])
				{
					case 'a':
						current_state = C;
						break;
					case 'b':
						current_state = D;
						break;
					default:
						current_state = ER;
						break;
				}
				break;
			case D:
				switch (str[i])
				{
					case 'a':
						current_state = C;
						break;
					case 'b':
						current_state = E;
						break;
					case 'c':
						current_state = F;
						break;
					default:
						current_state = ER;
						break;
				}
				break;
			case E:
				switch (str[i])
				{
					case 'a':
						current_state = C;
						break;
					case 'b':
						current_state = E;
						break;
					case 'c':
						current_state = F;
						break;
					default:
						current_state = ER;
						break;
				}
				break;
			case F:
				switch (str[i])
				{
					case 'b':
						current_state = G;
						break;
					case 'c':
						current_state = F;
						break;
					default:
						current_state = ER;
						break;
				}
				break;
			case G:
				switch (str[i])
				{
					case 'b':
						current_state = G;
						break;
					case 'c':
						current_state = F;
						break;
					default:
						current_state = ER;
						break;
				}
				break;
		}
		i++;
	} while (i != str.size() && current_state != ER);
	return (current_state == F);
}

int main()
{
	if (CheckStringCondition())
	{
		std::cout << "belongs" << '\n';
	}
	else
	{
		std::cout << "doesn't belong" << '\n';
	}
	return 0;
}