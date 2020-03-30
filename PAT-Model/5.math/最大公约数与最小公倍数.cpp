int gcd(int a, int b) {
	if (b == 0) return a;
	else return gcd(b, a%b);
}
int gcd(int a, int b) {
	return !b ? a : gcd(b, a%b);
}
//d为最大公约数，则最小公倍数为a/d*b;
