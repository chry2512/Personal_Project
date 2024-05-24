

// function to get cookie domain
const getCookieDomain = () => {
    const currentDomain = window.location.hostname;
    if (currentDomain === "test.it") {
        return "test.it";
    } else if (currentDomain === "test2.it") {
        return "test2.it.it";
    }
}

// function to get anonymous id from cookie

function getAnonymousIdFromCookie(cookieName) {
    var cookieMatch = document.cookie.match(new RegExp(cookieName + '=([^;]+)'));

    if (cookieMatch && cookieMatch[1]) {
        var encodedValue = cookieMatch[1];
        var decodedValue = decodeURIComponent(encodedValue);

        try {
            var jsonValue = JSON.parse(decodedValue);
            var anonymousId = jsonValue.anonymousId;
            return anonymousId || null;
        } catch (error) {
            return null;
        }
    } else {
        return null;
    }

}   

// function to set a cookie
function setCookie(cookieName, cookieValue, expirationDays) {
    var date = new Date();
    date.setTime(date.getTime() + (expirationDays * 24 * 60 * 60 * 1000));
    var expires = "expires=" + date.toUTCString();
    document.cookie = cookieName + "=" + cookieValue + ";" + expires + ";path=/";
}


// function to get a cookie value
function getCookie(cookieName) {
    var name = cookieName + "=";
    var decodedCookie = decodeURIComponent(document.cookie);
    var cookieArray = decodedCookie.split(';');
    for (var i = 0; i < cookieArray.length; i++) {
        var cookie = cookieArray[i];
        while (cookie.charAt(0) === ' ') {
            cookie = cookie.substring(1);
        }
        if (cookie.indexOf(name) === 0) {
            return cookie.substring(name.length, cookie.length);
        }
    }
    return "";
}

// function to delete a cookie
function deleteCookie(cookieName) {
    document.cookie = cookieName + "=; expires=Thu, 01 Jan 1970 00:00:00 UTC; path=/;";
}

// function to get session id from cookie
function getSessionIdFromCookie(cookieName) {
    var cookieMatch = document.cookie.match(new RegExp(cookieName + '=([^;]+)'));
    if (cookieMatch && cookieMatch[1]) {
        var encodedValue = cookieMatch[1];
        var decodedValue = decodeURIComponent(encodedValue);
        try {
            var jsonValue = JSON.parse(decodedValue);
            var sessionId = jsonValue.sessionId;
            return sessionId || null;
        } catch (error) {
            return null;
        }
    } else {
        return null;
    }
}

// function to set session id cookie
function setSessionIdCookie(cookieName, sessionId, expirationDays) {
    var sessionData = {
        sessionId: sessionId
    };
    var encodedValue = encodeURIComponent(JSON.stringify(sessionData));
    setCookie(cookieName, encodedValue, expirationDays);
}

// function to delete session id cookie
function deleteSessionIdCookie(cookieName) {
    deleteCookie(cookieName);
}