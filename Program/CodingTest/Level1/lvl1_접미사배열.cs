using System;

namespace CodingTest
{
    public static class SuffixArray
    {
        public static void Answer()
        {
            Console.WriteLine("lvl1_접미사배열");
            Console.WriteLine("");
            string my_string = "banana";
            var size = my_string.Length;
            var answer = new string[size];
            for (int i = 0; i < size; i++)
            {
                answer[i] = my_string.Substring(i, size - i);
                Console.WriteLine(answer[i]);
            }

            Array.Sort(answer);
        }
    }
}