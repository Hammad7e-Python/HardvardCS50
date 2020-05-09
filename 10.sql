Select
count(name)
from people
Join directors on people.id = directors.person_id
Join movies on directors.movie_id = movies.id
Join ratings on movies.id = ratings.movie_id
Where rating >= 9;