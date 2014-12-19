#include<map>
#include<string>
#include<cmath>
#include<iostream>

using namespace std;

class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        if(numerator==0) return "0";
        string result;
        if(numerator<0 ^ denominator<0 ) result+='-';   //���numerator<0��denominator<0����һ��Ϊ��
        //ת��Ϊ������INT_MINת��Ϊ���������������long long��long long int n=abs(INT_MIN)�õ���n��Ȼ�Ǹ��ģ�����д���������ʽ��
        long long int n=numerator,d=denominator;
        n=abs(n);d=abs(d);

        result+=to_string(n/d);  //��������
        long long int r=n%d;    //����r
        if(r==0) return result;
        else result+='.';
        //���洦��С�����֣��ù�ϣ��
        map<int,int> map;
        while(r){
            //�������r�Ƿ��ڹ�ϣ���У��ǵĻ���ʼѭ����
            if(map.find(r)!=map.end()){
                result.insert(map[r],1,'(');   //http://www.cplusplus.com/reference/string/basic_string/insert/
                result+=')';
                break;
            }
            map[r]=result.size();    //���������Ӧ��result���ĸ�λ��
            //��������
            r*=10;
            result+=to_string(r/d);
            r=r%d;
        }
        return result;
    }
};

int main()
{
    Solution s;
    cout<<s.fractionToDecimal(5,3)<<endl;
}
