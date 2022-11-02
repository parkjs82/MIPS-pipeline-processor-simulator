#include "Elements.cpp"

std::string encode(std::string operation, int rs, int rt, int rd);
void decode(int oper);
std::string DectoHex(int Dec);
std::string DectoBin(int len, int Dec);
int BintoDec();

std::string encode(std::string operation, int rs, int rt, int rd)
{
	std::string oper = "";
	if(operation == "add"){
		int shamt = 0;
		oper = DectoBin(6,OP_ADD) + DectoBin(5,rs) + DectoBin(5,rt)
		+ DectoBin(5,rd) + DectoBin(5,shamt) + DectoBin(6,FUNCT_ADD);
	}
	return oper;
}
void decode(int oper)
{

}
std::string DectoHex(int Dec)
{
	std::string Hex = "";
	std::string str[16] = {"0","1","2","3","4","5","6","7","8","9",
										"a","b","c","d","e","f"};
	while(Dec != 0){
		Hex = str[Dec%16] + Hex;
		Dec/=16;
	}
	while(Hex.length() < 8){
		Hex = "0"+Hex;
	}

	Hex = "0x" + Hex;
	return Hex;
}
std::string DectoBin(int len, int Dec)
{
	std::string Bin = "";
	while(Dec != 0){
		if(Dec%2 == 1) Bin = "1"+Bin;
		else Bin = "0"+Bin;
		Dec/=2;
	}
	while(Bin.length() < len){
		Bin = "0"+Bin;
	}
	return Bin;
}
int BintoDec(std::string Bin)
{
	int Dec = 0;
	for(int i = 0;i<Bin.length();i++){
		Dec*=2;
		if(Bin[i] == '1') Dec+=1;
	}

	return Dec;
}