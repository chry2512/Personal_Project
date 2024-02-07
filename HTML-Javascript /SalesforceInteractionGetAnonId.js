

// function to get cookie domain
const getCookieDomain = () => {
    const currentDomain = window.location.hostname;
    if (currentDomain === "7even.it") {
        return "7even.it";
    } else if (currentDomain === "tmlab.it") {
        return "tmlab.it";
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

// initialize Salesforce Interactions Map

SalesforceInteractions.init({
    subCookieDomain: getCookieDomain()
}).then(() => {
    const sitemap = {
        global: {},
        pageTypes: [{
                name: "homepage",
                isMatch: () => /tmlab/.test(window.location.href),
                interaction: {
                    name: "Homepage TMLAB"
                },
                user: {
                   
                    anonymousId: getAnonymousIdFromCookie("_sfid_1385")
                    
                }
            }
        ]
    };

    SalesforceInteractions.initSitemap(sitemap);
});


