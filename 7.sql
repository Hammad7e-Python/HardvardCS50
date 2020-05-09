Select
movies.title,
ratings.rating
from movies
Join ratings on ratings.movie_id = movies.id
where year = 2010
order by 2 desc, 1;