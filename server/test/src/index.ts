import {io} from "socket.io-client";

const socket = io("http://localhost:3000");

socket.on("hello", (arg) => {
    console.log(arg);
});

socket.emit("howareyou", "I'm good", "and it's ok + ", 101);


// socket.disconnect();