using System;

namespace CodingTest
{
    //https://school.programmers.co.kr/learn/courses/30/lessons/136798?language=csharp
    public static class Templars_Weapon
    {
        public static void Question()
        {
            Console.WriteLine("");
            Console.WriteLine("lvl1_기사단원의 무기");
            Console.WriteLine("");
            
            Console.WriteLine(Answer(5, 3, 2));  // 10
            Console.WriteLine(Answer(10, 3, 2)); // 21
        }

        public static int Answer(int number, int limit, int power) {
            int[] divisorsCount = new int[number + 1];
        
            for(int i = 1; i <= number; i++) {
                Console.WriteLine($"i : {i}");
                for(int j = i; j <= number; j += i) {
                    divisorsCount[j]++;
                    Console.Write($"/ j : {j} {divisorsCount[j]}");
                }
                Console.WriteLine($"");
            }
        
            int totalIron = 0;
            foreach(var count in divisorsCount) {
                Console.WriteLine($"{count}");  // 10
                if(count > limit) {
                    totalIron += power;
                } else {
                    totalIron += count;
                }
            }
            Console.Write("Answer:");
            return totalIron;
        }

    }
}