import java.util.LinkedHashMap;
import java.util.Map;

public LRUCache<K, V> extends LinkedHashMap<K, V> {
	private int cacheSize;
	private final int INITIAL_SIZE = 30;

  	public LRUCache(int cacheSize) {
  		super(INITIAL_SIZE, 0.75, true);
  		this.cacheSize = cacheSize;
	}

	/* https://docs.oracle.com/javase/7/docs/api/java/util/LinkedHashMap.html#removeEldestEntry%28java.util.Map.Entry%29 */
  	protected boolean removeEldestEntry(Map.Entry<K, V> eldest) {
  		return size() >= cacheSize;
 	}
}
