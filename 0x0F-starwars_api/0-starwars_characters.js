#!/usr/bin/node
const args = (process.argv);
const request = require('request');
const url = 'https://swapi-api.hbtn.io/api/films/' + args[2];
request(url, function (error, response, body) {
  if (!error) {
    const chars = JSON.parse(body).characters;
    printFunc(chars, 0);
  }
});
function printFunc (chars, i) {
  request(chars[i], function (error, response, body) {
    if (!error) {
      console.log(JSON.parse(body).name);
      if (i + 1 < chars.length) {
        printFunc(chars, i + 1);
      }
    }
  });
}
