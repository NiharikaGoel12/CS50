SELECT movies.title as title, ratings.rating as rating from movies
join ratings
on movies.id = ratings.movie_id
where movies.year = 2010 and rating is not null
order by rating DESC, title ASC;


--write a SQL query to list all movies released in 2010 and their ratings, in descending order by rating.
--For movies with the same rating, order them alphabetically by title.