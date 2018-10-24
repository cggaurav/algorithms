class LRUCache {
	constructor (capacity = 2) {
		this.capacity = capacity
		this.cache = new Map()
	}


	get (key) {

		if (this.cache.has(key)) {
			let value = this.cache.get(key)

			// The last key in the map is always the latest used
			this.cache.delete(key)
			this.cache.set(key, value)


			return value
		} else {
			return -1
		}

	}


	set (key, value) {
		// https://hackernoon.com/what-you-should-know-about-es6-maps-dc66af6b9a1e

		// The Map object holds key-value pairs and remembers the original insertion order of the keys.
		// https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Global_Objects/Map

		if (this.cache.size === this.capacity) {
			// Delete from the left end
			this.cache.delete(this.cache.keys().next().value)
		}

		this.cache.set(key, value)

	}

	put (key, value) {
		this.set(key, value)
	}
}

let cache = new LRUCache( 2 /* capacity */ );

console.log(cache.put(1, 1))
console.log(cache.put(2, 2))
console.log(cache.get(1)   )    // returns 1
console.log(cache.put(3, 3))    // evicts key 2
console.log(cache.get(2)   )    // returns -1 (not found)
console.log(cache.put(4, 4))    // evicts key 1
console.log(cache.get(1)   )    // returns -1 (not found)
console.log(cache.get(3)   )    // returns 3
console.log(cache.get(4)   )    // returns 4
