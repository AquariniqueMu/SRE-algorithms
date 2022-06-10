<!--
 * @Author: your name
 * @Date: 2022-04-21 19:08:41
 * @LastEditTime: 2022-04-21 19:08:41
 * @LastEditors: Please set LastEditors
 * @Description: 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 * @FilePath: \cpp\SRE Train\基本操作方法\vector二维动态数组输入.md
-->
//行首检测到换行就结束第一层循环
//需要在每一行前面加空格或其他字符操作，对是否结束第一层循环进行判断

while(true){
        for(temp = 0; cin >> temp;){
            tmp.push_back(temp);
            if(cin.get() == '\n')
                break;
        }
        matrix.push_back(tmp);
        vector <int>().swap(tmp);
        if(cin.get() == '\n')
                break;
    }