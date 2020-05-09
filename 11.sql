Select
movies.title
from people
Join stars on people.id = stars.person_id
Join movies on stars.movie_id = movies.id
Join ratings on movies.id = ratings.movie_id
Where people.name = 'Chadwick Boseman'
Order by rating desc
Limit 5;