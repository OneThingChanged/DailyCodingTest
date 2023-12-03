using System;
using System.Collections.Generic;

namespace CodingTest
{
    //https://school.programmers.co.kr/learn/courses/30/lessons/178871
    public class Running_Race
    {
        public static void Question()
        {
            Console.WriteLine("");
            Console.WriteLine("lvl1_달리기 경주");
            Console.WriteLine("");
            
            string[] players = {"mumu", "soe", "poe", "kai", "mine"};
            string[] callings = {"kai", "kai", "mine", "mine"};

            string[] result = Answer(players, callings);
        }

        public static string[] Answer(string[] players, string[] callings)
        {
            var dict = new Dictionary<string, int>();
            for (int i = 0; i < players.Length; i++)
            {
                dict.Add(players[i], i);
            }

            for (int i = 0; i < callings.Length; i++)
            {
                var curIndex = dict[callings[i]];
                var front = players[curIndex - 1];
                dict[callings[i]] = curIndex - 1;
                dict[front] = curIndex;
                players[curIndex - 1] = callings[i];
                players[curIndex] = front;
            }
            return players;
        }
    }
}