# Wrestling-Simulator

This simulator intends to replicate a conventional highschool/NCAA Wrestling tournament.

The simulation will includes 32 different teams, 8 in a single league. The season has a number of dual meets (team vs team) dates, 3 open tournaments and 1 league tournament.  The open tournaments will have no more than 2 league teams in them. The dual meet season will consist of 16 meets but during those matches, every league team MUST compete against every other league team. 

Wrestlers have a id number, teams have an id number as well (100, 200 through 3200) Wrestlers in team 100 would be 101, 102..etc…  The total number of wrestlers will vary per team. Wrestlers also have a ability score mean = 100, std. div = 15. Each will also have a Boolean value “injured” by default will be set to false.  Each wrestler’s weight will be determined randomly with a mean of 152 and a standard deviation of 27. Wrestlers also have a win loss record. Not only the total wins and losses but the ID numbers of those they have lost to.
A wrestler’s weight determines their lowest weight class they can wrestle up by 1 weight class + 1 pound from their current weight.. 
Ex:   a wrestler weighs 129 pounds therefore the 132 weight class they are allowed to be placed in the 132, 138 but to wrestle in the 145 wt class they would have had to weigh at least 133. 

Current weight classes are: 106, 113, 120, 126, 132, 138, 145, 152, 160, 170, 182, 195, 220 and 285. The minimum weight for 106 is 87 pounds, for 113 the minimum is 88.

A team may have multiple people for one weight class while missing someone at another. 

The sequence of events: 
Create the teams
Create the schedule
4 matches then a tournament
4 matches then a second tournament
4 matches then the third tournament
4 matches then the league tournament with teams # 100 through 800.




Bout resolution: 
Wrestler 214 vs 516
214 ability score of 105
516 has an ability score of 112
214 performs a random number with a mean of 105 std div of 15   120
516 performs a random number with a mean of 112 std div of 15  116
Wrestler 214 is victorious and the difference of 4 scores 3 team points (decision). 
Dual meet team scores: 
Win by 1 to 7    3 points
Win by 8 to 14  4 points
Win by 15 to 19 5 points (technical fall)
Win by 20+    6 points win by fall (pin)
After the bout is over a random number 1 to 100 is generated, if it is a 1 then one wrestler is chosen randomly to be injured with a duration of 1 to 6 weeks. 

Tournaments:
Tournament weeks 5, 10 and 15, open tournaments with random teams but no more than 2 league teams participating. 8 teams per tournament. 
Tournament Scoring 


