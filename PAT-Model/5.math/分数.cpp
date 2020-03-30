struct Fraction {
	int up, down;
};
Fraction reduction(Fraction result) {
	if (result.down < 0) {
		result.up = -result.up;//分母为负数，令分子和分母都变为相反数
		result.down = -result.down;
	}
	if (result.up == 0) {//如果分子为0
		result.down = 1;//令分母为1
	}
	else {//如果分子不为0，进行约分
		int d = gcd(abs(result.up), abs(result.down));//分子分母的最大公约数
		result.up /= d;
		result.down /= d;
	}
	return result;
}
