--In 12.sql, write a SQL query to list the titles of all movies in which both Johnny Depp and Helena Bonham Carter starred.
--Your query should output a table with a single column for the title of each movie.
--You may assume that there is only one person in the database with the name Johnny Depp.
--You may assume that there is only one person in the database with the name Helena Bonham Carter.

Select
movies.title
from people
Join stars on people.id = stars.person_id
Join movies on stars.movie_id = movies.id
Where people.name = 'Johnny Depp' AND movies.title IN
(
Select movies.title
From people
Join stars on people.id = stars.person_id
Join movies on stars.movie_id = movies.id
Where people.name = 'Helena Bonham Carter'
);
