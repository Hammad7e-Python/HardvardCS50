Select
name
from people
Join stars on people.id = stars.person_id
Join movies on stars.movie_id = movies.id
Where movies.title = 'Toy Story';