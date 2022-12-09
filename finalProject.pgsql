CREATE TABLE Users (
    userID SERIAL UNIQUE,
    username VARCHAR(20),
    profilePic TEXT,
    PRIMARY KEY (userID)
);

CREATE TABLE Post (
    postID SERIAL UNIQUE, 
    title VARCHAR(20),
    attachment TEXT, 
    likeCount INT,
    timeStmp timestamp not null default(CURRENT_TIMESTAMP),
    userid SERIAL UNIQUE,
    PRIMARY KEY (postID),
    FOREIGN KEY (userid) REFERENCES Users
);

CREATE TABLE Comment (
    commentID SERIAL UNIQUE,
    ctext VARCHAR(100),
    userid SERIAL UNIQUE,
    postid SERIAL UNIQUE,
    PRIMARY KEY (commentID),
    FOREIGN KEY (userid) REFERENCES Users,
    FOREIGN KEY (postid) REFERENCES Post
);