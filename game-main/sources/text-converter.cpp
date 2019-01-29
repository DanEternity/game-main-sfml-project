#include "text-converter.h"

void RichStringParse(sfe::RichText * q, std::string s, std::vector<void*> v1)
{
	// we will not clear current style, text, etc.
	int idx = 0;
	int n = s.size();
	std::string buffer = "";
	std::string c_buff = "";

	while (idx < n)
	{
		if (s[idx] == '@')
		{
			if (!buffer.empty())
			{
				*q << buffer;
				buffer.clear();
			}
			idx++;
			if (!(idx < n))
			{
				buffer += '@';
				break;
			}
			if (s[idx] == '[')
			{
				// we should find ]
				int right = idx + 1;
				while (s[right] != ']' && right < n - 1) right++;
				if (s[right] == ']')
				{
					c_buff = s.substr(idx + 1, right - idx - 1);
					if (!ConvertCommand(q, c_buff, v1))
					{
						buffer += "@[";
					}
					else
						idx = right;
				}
				else
				{
					buffer += "@[";
				}
			}
			else
				buffer += '@';
		}
		else
		{
			buffer += s[idx];
		}
		idx++;
	}

	*q << buffer; // send rest of string

}

bool ConvertCommand(sfe::RichText * q, std::string s, std::vector<void*> v1)
{
	
	int n = s.size();
	int idx = 0;
	
	while (idx < n - 1 && s[idx] != ':') { idx++; }
	if (s[idx] != ':')
		return false;

	std::string c_type = s.substr(0, idx);

	if (c_type == "color")
	{
		c_type = s.substr(idx + 1, n - idx);
		switch (c_type[0])
		{
		case '#':
			// DEC RGBA COLOR #ddd#ddd#ddd#ddd
		{
			int r, g, b, a;
			int il = 1;
			int i = 1;
			while (c_type[i] != '#' && i < c_type.size()) i++;
			r = StringToInt(c_type.substr(il, i - il));
			il = i + 1;
			i++;
			while (c_type[i] != '#' && i < c_type.size()) i++;
			g = StringToInt(c_type.substr(il, i - il));
			il = i + 1;
			i++;
			while (c_type[i] != '#' && i < c_type.size()) i++;
			b = StringToInt(c_type.substr(il, i - il));
			il = i + 1;
			i++;
			while (c_type[i] != '#' && i < c_type.size()) i++;
			a = StringToInt(c_type.substr(il, i - il));
			
			*q << sf::Color(r, g, b, a);

		}
			break;
		case '$':
			// HEX RGBA COLOR $hhhhhhhh
		{
			if (c_type.size() != 9)
			{
				Log("Error! Incorrenct HEX-color format");
				return false;
			}
			int r, g, b, a;
			int il = 1;
			int i = 1;
			
			r = HexToDec(c_type.substr(1, 2));
			il = i + 1;
			i++;
			
			g = HexToDec(c_type.substr(3, 2));
			il = i + 1;
			i++;
			
			b = HexToDec(c_type.substr(5, 2));
			il = i + 1;
			i++;
			
			a = HexToDec(c_type.substr(7, 2));

			*q << sf::Color(r, g, b, a);
		}
			break;
		default:
			// Name of color e.q. white, black...
			if (c_type == "white")
				*q << sf::Color::White;

			if (c_type == "black")
				*q << sf::Color::Black;

			if (c_type == "red")
				*q << sf::Color::Red;

			if (c_type == "green")
				*q << sf::Color::Green;

			if (c_type == "blue")
				*q << sf::Color::Blue;

			if (c_type == "yellow")
				*q << sf::Color::Yellow;

			if (c_type == "magenta")
				*q << sf::Color::Magenta;

			if (c_type == "cyan")
				*q << sf::Color::Cyan;
			break;
		}

	}
	
	if (c_type == "style")
	{
		c_type = s.substr(idx + 1, n - idx);
		if (c_type == "normal" || c_type == "regular")
		{
			*q << sf::Text::Style::Regular;
		}
		if (c_type == "italic")
		{
			*q << sf::Text::Style::Italic;
		}
		if (c_type == "bold")
		{
			*q << sf::Text::Style::Bold;
		}
		if (c_type == "underline" || c_type == "underlined")
		{
			*q << sf::Text::Style::Underlined;
		}
		if (c_type == "bold+italic" || c_type == "italic+bold")
		{
			*q << sf::Text::Style(sf::Text::Style::Bold | sf::Text::Style::Italic);
		}
		if (c_type == "bold+underlined" || c_type == "underlined+bold")
		{
			*q << sf::Text::Style(sf::Text::Style::Bold | sf::Text::Style::Underlined);
		}
		if (c_type == "italic+underlined" || c_type == "underlined+italic")
		{
			*q << sf::Text::Style(sf::Text::Style::Italic | sf::Text::Style::Underlined);
		}
		if (c_type.find("italic") != std::string::npos 
			&& c_type.find("bold") != std::string::npos 
			&& c_type.find("underlined") != std::string::npos)
		{
			*q << sf::Text::Style(sf::Text::Style::Italic | sf::Text::Style::Underlined | sf::Text::Style::Bold);
		}
	}
	
	if (c_type == "value")
	{
		c_type = s.substr(idx + 1, n - idx);
		int val = StringToInt(c_type.substr(1, c_type.size() - 1));
		switch (c_type[0])
		{
		case 'i':
		{
			int value = *static_cast<int*>(v1[val]);
			*q << std::to_string(value);
		}
			break;
		case 'f':
		{
			float value = *static_cast<float*>(v1[val]);
			*q << floatToString(value);
		}
			break;
		case 's':
		{
			std::string value = *static_cast<std::string*>(v1[val]);
			*q << value;
		}
			break;
		default:
			break;
		}
	}
	
	if (c_type == "default")
	{
		*q << sf::Text::Style::Regular;
		*q << sf::Color::White;
	}

	return true;
}

int StringToInt(std::string a)
{
	return atoi(a.c_str());
}

int HexToDec(std::string a)
{
	int x;
	std::stringstream ss;
	ss << std::hex << a;
	ss >> x;
	return x;
}
