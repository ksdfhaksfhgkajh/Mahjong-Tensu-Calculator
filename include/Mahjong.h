#ifndef MAHJONG_H
#define MAHJONG_H

#include <iostream>
#include <unordered_map>
#include <string>
#include <bitset>

enum MahjongType
{
	Man,
	Pin,
	Soo,
	Ji
};

enum TehaiType
{
	Tehai,
	Fuuro,
	Agari
};

const std::unordered_map<char, MahjongType> typemap =
{
		{'m', Man},
		{'p', Pin},
		{'s', Soo},
		{'j', Ji},
};

const std::unordered_map<int, std::string> jihai_map =
{
		{1, "東"},
		{2, "南"},
		{3, "西"},
		{4, "北"},
		{5, "白"},
		{6, "發"},
		{7, "中"}
};

enum FanType
{
	Riichi,
	Tanyao,
	Haku,
	Hatsu,
	Cyuu,
	Jifuu,
	Bafuu,
	Ippatsu,
	Menchintsumo,
	Iipeekoo,
	Pinfu,
	Haitei,
	Houtei,
	Rinsyan,
	Cyankan,
	SanSyoku,
	Ikki,
	ToiToi,
	Chiitoi,
	Cyanta,
	Daburii,
	Syousangen,
	Honrouto,
	Sanankoo,
	Doukoo,
	Sankantsu,
	Honitsu,
	Jyuncyan,
	Ryanpeekoo,
	Chinitsu,
	Tenhoo,
	Chihoo,
	Kokushi,
	Daisangen,
	Suuankoo,
	Syousuushii,
	Daisuushii,
	Tsuiisoo,
	Ryuuiisoo,
	Chinrouto,
	Cyuuren,
	Suukantsu
};

class Mahjong
{
	friend std::ostream& operator<< (std::ostream&, const Mahjong&);

public:
	using MahjongData = std::pair<int, MahjongType>;
	using MahjongString = std::vector<MahjongData>;

private:
	std::string _mahjong_string{};
	std::bitset<42> _yakulist{};
	int _jifuu{};
    int _bafuu{};
	bool _is_tsumo{};

	MahjongData _agarihai;
	MahjongString _tehai;
	std::vector<MahjongString> _fuuro;

	void _stringToMahjong();

public:
	explicit Mahjong(std::string&& str);

	std::pair<bool, int> yakuDeter() const;

	//int FuCalcu() const;

	//int Tensu() const;

	bool isRiichi() const;
	bool isIppatsu() const;
	bool isRinsyan() const;
	bool isHaitei() const;
	bool isHoutei() const;
	bool isCyankan() const;
	bool isDaburii() const;

	bool isTanyao() const;
	bool isCyuu() const;
	bool isHatsu() const;
	bool isHaku() const;
	bool isJifuu() const;
	bool isBafuu() const;
	bool isMenchintsumo() const;
	bool isIipeekoo() const;
	bool isPinfu() const;

	bool isSanSyoku() const;
	bool isIkki() const;
	bool isSanankoo() const;
	bool isToiToi() const;
	bool isChiitoi() const;
	bool isCyanta() const;
	bool isSyousangen() const;
	bool isHonrouto() const;
	bool isDoukoo() const;
	bool isSankantsu() const;

	bool isHonitsu() const;
	bool isJyuncyan() const;
	bool isRyanpeekoo() const;

	bool isChinitsu() const;

	bool isSuuankoo() const;
	bool isDaisangen() const;
	bool isKokushi() const;
	bool isDaisuushii() const;
	bool isSyousuushii() const;
	bool isChinrouto() const;
	bool isSuukantsu() const;
	bool isTsuiisoo() const;
	bool isRyuuiisoo() const;
	bool isCyuuren() const;
};

std::ostream& operator<< (std::ostream& o, const Mahjong& my_tehai);

#endif