/*
 * @Author: your name
 * @Date: 2022-03-09 21:22:04
 * @LastEditTime: 2022-03-09 21:22:04
 * @LastEditors: Please set LastEditors
 * @Description: 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 * @FilePath: \cpp\或与加.cpp
 */

/*
链接：https://www.nowcoder.com/questionTerminal/729f5e6e2acc4f3cb14a2262888f86fb
来源：牛客网

x+y=x|y
这里可以推出一个结论，x&y=0。也就是说，在二进制上看，x取1的地方，y必定不能取1。从最低位考虑，若x与y在某一位上同时取1，则x+y在该位上为0，x|y在该位上为1，前面说这是最低一位x y同时取1，也就是说没有更低位加法的进位，所以这里两个结果不相等，出现了矛盾。
例子：
x = 001010
y = 110110
x + y =  1000000
x | y = 111110
偏差产生的原因是倒数第二位，x+y=0 x|y=1 且倒数第一位加法没有进位
结论：x在二进制取1的位上，y不能做出改变，只能取0
----方法----
有了上述结论，可以进一步推出只要在x取0的地方，y可以做出改变
例如
x = 10010010011
y = 00000000(0)00   k = 0
y = 00000000(1)00   k = 1
y = 0000000(1)(0)00 k = 2
y = 0000000(1)(1)00 k = 3
y = 00000(1)0(0)(0)00 k = 4
y = 00000(1)0(0)(1)00 k = 5
...
注意观察括号里的数，为x取0的比特位，而如果把括号里的数连起来看，正好等于k。
得出结论，把k表示成二进制数，填入x取0的比特位，x取1的比特位保持为0，得到y。
---代码说明---
思路有了，接着就是代码，显然用位操作是最合适的方式。
循环的思想是每次取得k的最低一位，填入到低位开始，x中比特位为0的位置上。
所以用while来判断k是否大于0，若是，说明k还未完全填完
循环体内，需要找到x当前可以填的位置，我们用bitNum来从右往左扫描x的每一位
*/



#include <iostream>

using namespace std;

int main()
{
	long long x, k;
	cin>>x>>k;
	long long bitNum = 1;
	long long ans = 0;
	while(k)
	{
		if((x & bitNum) == 0)
		{
			ans += (bitNum * (k & 1));
			k >>= 1;
		}
		bitNum <<= 1;
	}
	cout<<ans<<endl;
	return 0;
}
