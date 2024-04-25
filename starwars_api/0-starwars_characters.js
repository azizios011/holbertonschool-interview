#!/usr/bin/node

const request = require("request");
const movieId = process.argv[2];

if (!movieId) {
    console.log("Please provide a movie ID as the first argument.");
    process.exit(1);
}

const URL = `https://swapi-api.hbtn.io/api/films/${movieId}/`;

request(URL, (error, response, body) => {
    if (error) {
        console.error('Error:', error);
    } else if (response.statusCode !== 200) {
        console.error('Unexpected status code:', response.statusCode);
    } else {
        const film = JSON.parse(body);
        const charactersUrls = film.characters;
        fetchCharacters(charactersUrls);
    }
});

function fetchCharacters(urls) {
    const promises = urls.map(url => {
        return new Promise((resolve, reject) => {
            request(url, (error, response, body) => {
                if (error) {
                    reject(error);
                } else if (response.statusCode !== 200) {
                    reject(new Error(`Unexpected status code: ${response.statusCode}`));
                } else {
                    const character = JSON.parse(body);
                    resolve(character.name);
                }
            });
        });
    });

    Promise.all(promises)
        .then(characters => {
            characters.forEach(character => console.log(character));
        })
        .catch(error => {
            console.error('Error fetching characters:', error);
        });
}
