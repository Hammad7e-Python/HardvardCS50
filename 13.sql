Select
distinct(name)
from people
Join stars on people.id = stars.person_id
Join movies on stars.movie_id = movies.id
Where movies.title IN
(
Select distinct(movies.title)
from people
Join stars on people.id = stars.person_id
Join movies on stars.movie_id = movies.id
Where people.name = 'Kevin Bacon' and people.birth = 1958
)
and people.name != 'Kevin Bacon';