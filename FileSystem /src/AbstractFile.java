public abstract class AbstractFile
{
	private String name;
	private int position;
	private int parent;

	public AbstractFile()
	{
		this.name = "";
		this.position = -1;
		this.parent = -1;
	}

	public AbstractFile(String name, int position, int parent)
	{
		this.name = name;
		this.position = position;
		this.parent = parent;
	}

	public String getFileName()
	{
		return this.name;
	}

	public void setFileName(String name)
	{
		this.name = name;
	}

	public int getFilePosition()
	{
		return this.position;
	}

	public int getFileParent()
	{
		return this.parent;
	}

	public void setFileParent(int parent)
	{
		this.parent = parent;
	}

	public void setFilePos(int position)
	{
		this.position = position;
	}
}