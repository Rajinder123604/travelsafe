console.log("RUNNING FILE:", __filename);  // 👈 sabse upar
console.log("FILE LOADED");

const express = require("express");
const mongoose = require("mongoose");
const cors = require("cors");

const app = express();

app.use(cors());
app.use(express.json());

// 🔥 MongoDB CONNECT
mongoose.connect("mongodb://127.0.0.1:27017/touristDB")
.then(() => console.log("✅ MongoDB Connected"))
.catch(err => console.log("❌ DB Error:", err));

// ✅ TEST ROUTE
app.get("/", (req, res) => {
    res.send("Server working");
});

// 🚀 START SERVER
app.listen(3000, () => {
    console.log("Server running on http://localhost:3000");
});