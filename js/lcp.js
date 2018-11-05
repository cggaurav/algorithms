function lcp (strings) {

	return strings.reduce((l, r) => {

	    while(l !== r.slice(0, l.length)) {
	        l = l.slice(0, -1)
	    }

	    return l
	})

}



console.log(lcp(["interspecies", "intermediate", "interrogation"]))