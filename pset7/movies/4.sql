SELECT COUNT(movies.title) FROM movies 
    JOIN ratings ON ratings.movie_id = movies.id
    Where ratings.rating = 10.0;