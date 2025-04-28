using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
namespace palonrd
{
    internal class Program
    {
        static bool palindrom(string s)
        {
            for(int i=0,j=s.Length-1; i<j;i++,j--)
                if(s[i] != s[j]) return false;
            return true;
        }
        static void Main(string[] args)
        {
            string [] S = Console.ReadLine().Split(' ');
            List<string> C = new List<string>();
            foreach (string s in S)
                if(s!="" && palindrom(s)) C.Add(s);
            if (C.Count == 0) Console.WriteLine("nu exista");
            else
            {
                C.Sort();
                int l = 1;
                for (int i = 0; i < C.Count - 1; i++)
                    if (C[i] == C[i + 1]) l++;
                    else
                    {
                        Console.WriteLine(C[i] + " " + l);
                        l = 1;
                    }
                Console.WriteLine(C[C.Count - 1] + " " + l);
            }
            Console.ReadKey();
        }
    }
}