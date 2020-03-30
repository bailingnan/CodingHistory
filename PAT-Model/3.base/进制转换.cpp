int y = 0, product = 1;//p进制转换为10进制
while (x != 0) {
	y = y + (x % 10)*product;
	x = x / 10;
	product = product * p;
}
//十进制数y转化为Q进制
int z[40], num = 0;
do {
	z[num++] = y % Q;//除基取余
	y = y / Q;
} while (y != 0);
