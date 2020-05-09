Select
--distinct(count(people.name))
Distinct(people.name)
from stars
Join people on stars.person_id = people.id
Join movies on stars.movie_id = movies.id
join ratings on stars.movie_id = ratings.movie_id
join directors on stars.movie_id = directors.movie_id
Where movies.year = 2004
Order by birth;