Select
avg(rating)
from ratings
JOIN movies on ratings.movie_id = movies.id
where year = 2012;