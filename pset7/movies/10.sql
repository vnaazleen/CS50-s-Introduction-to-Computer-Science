SELECT name
FROM people
INNER JOIN directors ON people.id = directors.person_id
INNER JOIN movies ON movies.id = directors.movie_id
INNER JOIN ratings ON ratings.movie_id = movies.id
WHERE ratings.rating >=  9.0;