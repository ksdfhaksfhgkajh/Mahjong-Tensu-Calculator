#include "Mahjong.h"

// �ж�����
//std::pair<bool,int> Mahjong::YakuDeter() const
//{
//	bool is_yakuman=false;
//	int fan_count = 0;
//	int yakuman_count = 0;
//
//
//
//}

Mahjong::Mahjong(std::string str = "")
	:_mahjong_string(str)
{
	_String2Mahjong();
}

//����������ת���ɿ�������
void Mahjong::_String2Mahjong()
{
	MahjongType mahjong_type;
	TehaiType tehai_type = Tehai;
	MahjongString sub_fuuro;
	int tehai_num = 0;

	for (auto it = _mahjong_string.begin(); it != _mahjong_string.end(); it++)
	{
		auto checkmap = typemap.find(*it);
		if (checkmap != typemap.end())
		{
			mahjong_type = (*checkmap).second;
		}
		else if (*it == ' ')
		{
			switch (tehai_type)
			{
			case Tehai:
				tehai_type = Agari;
				break;
			case Agari:
				tehai_type = Fuuro;
				sub_fuuro.reserve(4);
				break;
			case Fuuro:
				if (sub_fuuro.size() > 4 || sub_fuuro.size() < 3)
				{
					std::cerr << "Error: Fuuro Size:" << sub_fuuro.size() << std::endl;
					throw std::runtime_error("Fuuro exceeds maximum tile count");
				}
				_fuuro.push_back(sub_fuuro);
				sub_fuuro.clear();
			}
		}
		else if (*it > '0' && *it <= '9')
		{
			++tehai_num;
			switch (tehai_type)
			{
			case Tehai:
				_tehai.push_back(std::make_pair(static_cast<int>(*it - '0'), mahjong_type));
				break;
			case Fuuro:
				sub_fuuro.push_back(std::make_pair(static_cast<int>(*it - '0'), mahjong_type));
				break;
			case Agari:
				_agarihai = std::make_pair(static_cast<int>(*it - '0'), mahjong_type);
			}
		}
		else
		{
			std::cerr << "Invalid input: " << *it << std::endl;
			throw std::runtime_error("Mahjong string contains invalid character");
		}
	}
	if (tehai_num < 14 || tehai_num >18)
	{
		std::cerr << "Error: Tehai Number: " << tehai_num << std::endl;
		throw std::runtime_error("Tehai wrong tile count");
	}
	// ȷ�����ĸ�¶�����뵽 fuuro ��
	if (!sub_fuuro.empty())
	{
		if (sub_fuuro.size() > 4 || sub_fuuro.size() < 3)
		{
			std::cerr << "Error: Fuuro Size: " << sub_fuuro.size() << std::endl;
			throw std::runtime_error("Fuuro wrong tile count");
		}
		_fuuro.push_back(sub_fuuro);
	}
}

// ��ӡ�����������
std::ostream& operator<< (std::ostream& o, const Mahjong& my_tehai)
{
	auto typecout = [&o](const Mahjong::MahjongData& tehai)
	{
		switch (tehai.second)
		{
		case Man:
			o << tehai.first << 'm' << ' ';
			break;
		case Pin:
			o << tehai.first << 'p' << ' ';
			break;
		case Soo:
			o << tehai.first << 's' << ' ';
			break;
		case Ji:
			auto checkmap = jihai_map.find(tehai.first);
			if (checkmap != jihai_map.end())
				o << (*checkmap).second << ' ';
		}
	};
	o << "����Ϊ��" << std::endl;
	for (const auto& tehai_s : my_tehai._tehai)
		typecout(tehai_s);
	o << std::endl << "������Ϊ��" << std::endl;
	typecout(my_tehai._agarihai);
	o << std::endl << "��¶Ϊ��" << std::endl;
	if (my_tehai._fuuro.size() == 0)
		o << "��" ;
	else
	{
		for (const auto& sub_fuuro : my_tehai._fuuro)
		{
			for (const auto& fuuro_s : sub_fuuro)
				typecout(fuuro_s);
			o << std::endl;
		}
	}
	return o;
}



