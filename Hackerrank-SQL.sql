Revising the Select Query I
----------------------------------------
SELECT * FROM CITY WHERE COUNTRYCODE = 'USA' AND POPULATION > 100000;


Revising the Select Query II
----------------------------------------
SELECT NAME FROM CITY WHERE POPULATION > 120000 AND COUNTRYCODE = 'USA';


Select All
----------------------------------------
SELECT * FROM CITY;


Select By ID
----------------------------------------
SELECT * FROM CITY WHERE ID = 1661;


Japanese Cities' Attributes
----------------------------------------
SELECT * FROM CITY WHERE COUNTRYCODE = 'JPN';


Japanese Cities' Names
----------------------------------------
SELECT NAME FROM CITY WHERE COUNTRYCODE = 'JPN';


Weather Observation Station 1
----------------------------------------
SELECT CITY, STATE FROM STATION;


Weather Observation Station 3
----------------------------------------
SELECT DISTINCT CITY FROM STATION WHERE MOD(ID, 2) = 0;

Higher Than 75 Marks
----------------------------------------
SELECT NAME FROM STUDENTS WHERE MARKS > 75 ORDER BY SUBSTR(NAME, LENGTH(NAME) - 2, 3) ASC, ID ASC;


Employee Names
----------------------------------------
SELECT NAME FROM EMPLOYEE ORDER BY NAME ASC;


Employee Salaries
----------------------------------------
SELECT NAME FROM EMPLOYEE WHERE SALARY > 2000 and MONTHS < 10 ORDER BY EMPLOYEE_ID ASC;


Type of Triangle
----------------------------------------
SELECT CASE WHEN A + B > C AND A+C>B AND B+C>A THEN CASE WHEN A = B AND B = C THEN 'Equilateral' WHEN A = B OR B = C OR A = C THEN 'Isosceles' WHEN A != B OR B != C OR A != C THEN 'Scalene' END ELSE 'Not A Triangle' END FROM TRIANGLES;


The PADS
----------------------------------------
SELECT CONCAT(NAME, '(', SUBSTR(OCCUPATION, 1, 1), ')') FROM OCCUPATIONS ORDER BY NAME ASC;
SELECT CONCAT('There are a total of ', count(OCCUPATION), ' ', lower(occupation), 's.') FROM OCCUPATIONS GROUP BY OCCUPATION ORDER BY COUNT(OCCUPATION), OCCUPATION ASC


Binary Tree Nodes
----------------------------------------
SELECT N, if(P is NULL, 'Root', if((SELECT COUNT(*) FROM BST WHERE P = B.N) > 0, 'Inner', 'Leaf')) FROM BST as B order by N 


New Companies
----------------------------------------
select c.company_code, c.founder, 
    count(distinct l.lead_manager_code), count(distinct s.senior_manager_code), 
    count(distinct m.manager_code),count(distinct e.employee_code) 
from Company c, Lead_Manager l, Senior_Manager s, Manager m, Employee e 
where c.company_code = l.company_code 
    and l.company_code=s.company_code 
    and s.company_code=m.company_code 
    and m.company_code=e.company_code
group by c.company_code, c.founder order by c.company_code;


Revising Aggregations - The Count Function
----------------------------------------
SELECT COUNT(DISTINCT NAME) FROM CITY WHERE POPULATION > 100000


Revising Aggregations - The Sum Function
----------------------------------------
SELECT SUM(POPULATION) FROM CITY WHERE DISTRICT = 'California'


Revising Aggregations - Averages
----------------------------------------
SELECT AVG(POPULATION) FROM CITY WHERE DISTRICT = 'California'


Average Population
----------------------------------------
SELECT ROUND(AVG(POPULATION) - 0.5) FROM CITY


Japan Population
----------------------------------------
SELECT sum(population) FROM city WHERE COUNTRYCODE = 'JPN'


Weather Observation Station 4
----------------------------------------
SELECT (COUNT(CITY) - COUNT(DISTINCT CITY)) FROM STATION;
                            

Weather Observation Station 5
----------------------------------------
SELECT CITY, CHAR_LENGTH(CITY) FROM STATION ORDER BY CHAR_LENGTH(CITY) ASC, CITY LIMIT 1; 
SELECT CITY, CHAR_LENGTH(CITY) FROM STATION ORDER BY CHAR_LENGTH(CITY) DESC, CITY LIMIT 1;


Weather Observation Station 6
----------------------------------------
SELECT DISTINCT CITY FROM STATION WHERE SUBSTR(CITY, 1, 1) in ('a', 'i', 'e', 'o', 'u');

                            
Weather Observation Station 7
----------------------------------------
SELECT DISTINCT CITY FROM STATION WHERE CITY REGEXP('.[aeiou]$');

                            
Weather Observation Station 8
----------------------------------------
SELECT DISTINCT CITY FROM STATION WHERE CITY REGEXP('^[aeiou]') and CITY REGEXP('[aeiou]$');


Weather Observation Station 9
----------------------------------------
SELECT DISTINCT CITY FROM STATION WHERE CITY REGEXP('^[^aeiou]');


Weather Observation Station 10
----------------------------------------
SELECT DISTINCT CITY FROM STATION WHERE CITY REGEXP('.[^aeiou]$');


Weather Observation Station 11
----------------------------------------
SELECT DISTINCT CITY FROM STATION WHERE CITY REGEXP('^[^aeiou]') or CITY REGEXP('.[^aeiou]$');


Weather Observation Station 12
----------------------------------------
SELECT DISTINCT CITY FROM STATION WHERE CITY REGEXP('^[^aeiou]') and CITY REGEXP('.[^aeiou]$');

Population Density Difference
----------------------------------------
SELECT (MAX(POPULATION) - MIN(POPULATION)) FROM CITY


The Blunder
----------------------------------------
SELECT CEIL(AVG(Salary)-AVG(REPLACE(Salary,'0',''))) FROM EMPLOYEES;


Top Earner
----------------------------------------
SELECT ROUND(SUM(LAT_N), 2), ROUND(SUM(LONG_W), 2) FROM STATION


Weather Observation Station 2
----------------------------------------
SELECT AVG(POPULATION) FROM CITY WHERE DISTRICT = 'California'


Weather Observation Station 13
----------------------------------------
SELECT ROUND((SUM(LAT_N) - .00005), 4) FROM STATION WHERE LAT_N BETWEEN 38.788 AND 137.2345


Weather Observation Station 14
----------------------------------------
SELECT ROUND((MAX(LAT_N) - .00005), 4) FROM STATION WHERE LAT_N < 137.2345


Weather Observation Station 15
----------------------------------------
SELECT ROUND(LONG_W, 4) FROM STATION WHERE LAT_N = (SELECT MAX(LAT_N) FROM STATION WHERE LAT_N < 137.2345)


Weather Observation Station 16
----------------------------------------
SELECT ROUND(MIN(LAT_N), 4) FROM STATION WHERE LAT_N > 38.778


Weather Observation Station 17
----------------------------------------
SELECT ROUND(LONG_W, 4) FROM STATION WHERE LAT_N = (SELECT MIN(LAT_N) FROM STATION WHERE LAT_N > 38.778)


Weather Observation Station 18
----------------------------------------
SELECT round((max(LAT_N) - min(LAT_N) + max(LONG_W) - min(LONG_W))*10000)*0.0001 FROM STATION


Weather Observation Station 19
----------------------------------------
SELECT round(sqrt(POWER((max(LAT_N) - min(LAT_N)), 2) + POWER((max(LONG_W) - min(LONG_W)), 2))*10000)*0.0001 FROM STATION


Weather Observation Station 20
----------------------------------------
 Select round(S.LAT_N,4) from station S where (select count(Lat_N) from station where Lat_N < S.LAT_N ) = (select count(Lat_N) from station where Lat_N > S.LAT_N)



