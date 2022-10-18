#include <iostream>
#include <cstdio>

using namespace std;

class Simple{
    private:
        int s1;
        double s2;
    public:
        Simple() : s1(0), s2(0) {}
        Simple(const int &i,const double &d) : s1(i), s2(d) {}
        Simple(const Simple & si) : s1(si.s1), s2(si.s2) {}
        void plusOne() {s1+=1;s2+=1;}
        ostream& operator<<(ostream& os) {return os<<s1<<" "<<s2;}
    friend int main();
};

int main() {
    Simple simp(1,1.1);
    Simple simp2;
    Simple simp3;
    FILE *fl;
    fl = fopen("new_file.txt","w");
    fwrite(&simp, sizeof(class Simple), 1, fl);
    fclose(fl);
    fl = fopen("new_file.txt","r");
    fread(&simp2, sizeof(class Simple), 1, fl);
    simp2.plusOne();
    fclose(fl);
    fl = fopen("new_file.txt","w");
    fseek(fl,0,SEEK_SET);
    fwrite(&simp2, sizeof(class Simple), 1, fl);
    fclose(fl);
    fl = fopen("new_file.txt","r");
    fread(&simp3, sizeof(class Simple), 1, fl);
    simp3 << cout;
    fclose(fl);
}